import math

def equacaoSegundoGrau(a, b, c):
    delta = (b*b) - (4*a*c)
    if(delta < 0):
        return "Sem soluções reais"

    x1 = (-b + math.sqrt(delta))/(2 * a)
    x2 = (-b - math.sqrt(delta))/(2 * a)
    
    if(x1 != x2):
        answers = [x1, x2];
        return answers

    return x1

print(equacaoSegundoGrau(1, 2, 1))     # Uma solução real
print(equacaoSegundoGrau(1, 4, 3))     # Duas soluções reais
print(equacaoSegundoGrau(5, 2, 6))     # Sem soluções reais