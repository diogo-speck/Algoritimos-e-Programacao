calc= input ("Bem-Vindo a Caluladora de Médias da Univali onde a nota e o peso máximo é 10, deseja usa-lá? (s/n)")
if calc == "s":
    n1 = float (input("Digite a nota da m1:"))
    p1 = float (input("Digite a nota da p1:"))
    n2 = float (input("Digite a nota da m2:"))
    p2 = float (input("Digite a nota da p2:"))
    n3 = float (input("Digite a nota da m3:"))
    p3 = float (input("Digite a nota da p3:"))
    media = (n1*p1+n2*p2+n3*p3)/10
    if media < 5.75:
        print (f"Sua média ponderada é: {media}")
        print ("Infelizmente você terá que pagar mais um semestre $-$")
    elif media > 5.75 and media <= 10:
        print (f"Sua média ponderada é: {media}")
        print ("Parabéns, você foi aprovado")
    elif 0:
        print (f"Sua média ponderada é: {media}")
        print ("Você bateu o recorde de média mais baixa")
    else:
        print (f"Sua média ponderada seria: {media}")
        print ("Preencha as notas corretamente por favor")
print ("Certo, agora vamos aprender sobre os operadores relacionais então")
try:
    a = float (input ("Digite um valor para A: "))
    b = float (input ("Digite um valor para B: "))
    if a == b:
        print (f"{a} = {b}")
    else:
        print (f"{a} != {b}")
        if a>b:
            print (f"{a} > {b}")
        else:
            print (f"{a} < {b}")
except ValueError:
    print ("Por favor digite números reais respeitando o padrão")