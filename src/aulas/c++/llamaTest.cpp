#include <iostream>
#include <vector>
#include <string>
#include "/home/diogospeck/Documents/Prog/LlamaC++/build/llama.cpp/include/llama.h"

using namespace std;

int main() {
    // 1. Inicializar o backend global
    llama_backend_init();

    // 2. Configurar parâmetros de carregamento
    llama_model_params model_params = llama_model_default_params();
    const char * model_path = "/home/diogospeck/Documents/Prog/Algoritimos-e-Programacao/src/aulas/c++/qwen3b.gguf";

    // 3. Carregar o modelo GGUF
    llama_model * model = llama_model_load_from_file(model_path, model_params);
    if (model == nullptr) {
        cerr << "Erro: Falha ao carregar o modelo de " << model_path << endl;
        llama_backend_free();
        return 1;
    }

    // 4. Extrair o vocabulário (Vocab)
    const struct llama_vocab * vocab = llama_model_get_vocab(model);

    // 5. Criar o contexto de execução
    llama_context_params ctx_params = llama_context_default_params();
    ctx_params.n_ctx = 2048; 
    llama_context * ctx = llama_init_from_model(model, ctx_params);
    if (ctx == nullptr) {
        cerr << "Erro: Falha ao criar o contexto de execução." << endl;
        llama_model_free(model);
        llama_backend_free();
        return 1;
    }

    // Limpa a tela antes do Input do usuário
    cout << "\033[2J\033[H";
    
    // 6. Entrada de texto
    string prompt;
    cout << "Insira um prompt: ";
    getline(cin, prompt);

    if (prompt.empty()) {
        prompt = "Hello"; 
    }

    // 7. Tokenização do Prompt original
    vector<llama_token> tokens(prompt.size() + 4);
    int n_tokens = llama_tokenize(vocab, prompt.c_str(), prompt.size(), tokens.data(), tokens.size(), true, true);
    if (n_tokens <= 0) {
        cerr << "Erro: A tokenização falhou." << endl;
        llama_free(ctx);
        llama_model_free(model);
        llama_backend_free();
        return 1;
    }
    tokens.resize(n_tokens);

    // Limpa a tela e prepara o cabeçalho de resposta
    cout << "\033[2J\033[H";
    cout << "User: " << prompt << "\n\nResposta do modelo: " << flush;

    // 8. Configuração Robusta do Sampler (Essencial para o Qwen/Llama3)
    llama_sampler * sampler = llama_sampler_chain_init(llama_sampler_chain_default_params());
    llama_sampler_chain_add(sampler, llama_sampler_init_temp(0.7f)); // Controla a criatividade
    llama_sampler_chain_add(sampler, llama_sampler_init_dist(0));      // Permite ler a distribuição de probabilidades dos tokens

    // 9. LOOP DE GERAÇÃO AUTOREGRESSIVA (Gera o texto completo)
    int max_tokens_to_generate = 200; // Limite de tamanho da resposta
    int n_past = 0;                  // Controla a posição da memória do contexto

    // Primeiro passo: Processar todo o prompt inicial de uma vez só
    llama_batch batch = llama_batch_init(n_tokens, 0, 1);
    for (int i = 0; i < n_tokens; ++i) {
        batch.token[i]    = tokens[i];
        batch.pos[i]      = i;
        batch.n_seq_id[i] = 1;
        batch.seq_id[i][0] = 0; 
        batch.logits[i]   = (i == n_tokens - 1); // Queremos logits apenas do último token do prompt
    }
    batch.n_tokens = n_tokens;

    for (int step = 0; step < max_tokens_to_generate; ++step) {
        // Envia o lote atual para a GPU/CPU processar
        if (llama_decode(ctx, batch) != 0) {
            cerr << "\nErro: Falha ao decodificar os tokens." << endl;
            break;
        }

        // Avança o contador do que já foi processado na memória
        n_past += batch.n_tokens;

        // Amostra o próximo token usando o Sampler corrigido
        llama_token predicted_token = llama_sampler_sample(sampler, ctx, batch.n_tokens - 1);

        // Verifica se o modelo decidiu parar (Token de fim de texto / EOS)
        if (llama_vocab_is_eog(vocab, predicted_token)) {
            break; 
        }

        // Converte o token gerado em texto real e imprime imediatamente (Streaming)
        char buf[256];
        int n_chars = llama_token_to_piece(vocab, predicted_token, buf, sizeof(buf), 0, true);
        if (n_chars > 0) {
            cout << string(buf, n_chars) << flush;
        }

        // Prepara o lote para a PRÓXIMA iteração (Passando apenas 1 token gerado por vez)
        llama_batch_free(batch);
        batch = llama_batch_init(1, 0, 1);
        batch.token[0]    = predicted_token;
        batch.pos[0]      = n_past;
        batch.n_seq_id[0] = 1;
        batch.seq_id[0][0] = 0;
        batch.logits[0]   = true; // Sempre precisamos dos logits para adivinhar a próxima palavra
        batch.n_tokens    = 1;
    }

    cout << "\n\n[Geração Finalizada]" << endl;

    // 10. Limpeza completa de memória
    llama_batch_free(batch);
    llama_sampler_free(sampler);
    llama_free(ctx);
    llama_model_free(model);
    llama_backend_free();

    return 0;
}