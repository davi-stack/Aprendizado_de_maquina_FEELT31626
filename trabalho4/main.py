from typing import Dict
# Dígito 0


# Dígito 0 como vetor
digit_0 = [1, 0, 0, 0, 1, 
           1, 1, 0, 1, 1, 
           1, 0, 1, 0, 1, 
           1, 0, 0, 0, 1, 
           1, 1, 1, 1, 1]

# Dígito 1 como vetor
digit_1 = [0, 1, 0, 0, 0,
           1, 1, 0, 0, 0,
           0, 1, 0, 0, 0,
           0, 1, 0, 0, 0,
           1, 1, 1, 0, 0]

# Dígito 2 como vetor
digit_2 = [1, 1, 1, 0, 0,
           0, 0, 0, 1, 0,
           0, 0, 1, 0, 0,
           0, 1, 0, 0, 0,
           1, 1, 1, 1, 0]

# Dígito 3 como vetor
digit_3 = [1, 1, 1, 0, 0,
           0, 0, 0, 1, 0,
           0, 1, 1, 1, 0,
           0, 0, 0, 1, 0,
           1, 1, 1, 0, 0]

# Dígito 4 como vetor
digit_4 = [1, 0, 0, 1, 0,
           1, 0, 0, 1, 0,
           1, 1, 1, 1, 1,
           0, 0, 0, 1, 0,
           0, 0, 0, 1, 0]

# Dígito 5 como vetor
digit_5 = [1, 1, 1, 1, 1,
           1, 0, 0, 0, 0,
           1, 1, 1, 0, 0,
           0, 0, 0, 1, 0,
           1, 1, 1, 0, 0]

# Dígito 6 como vetor
digit_6 = [0, 1, 1, 1, 0,
           1, 0, 0, 0, 0,
           1, 1, 1, 1, 0,
           1, 0, 0, 1, 0,
           0, 1, 1, 0, 0]

# Dígito 7 como vetor
digit_7 = [1, 1, 1, 1, 0,
           0, 0, 0, 1, 0,
           0, 0, 1, 0, 0,
           0, 1, 0, 0, 0,
           1, 0, 0, 0, 0]

# Dígito 8 como vetor
digit_8 = [0, 1, 1, 1, 0,
           1, 0, 0, 0, 1,
           0, 1, 1, 1, 0,
           1, 0, 0, 0, 1,
           0, 1, 1, 1, 0]

# Dígito 9 como vetor
digit_9 = [0, 1, 1, 1, 0,
           1, 0, 0, 0, 1,
           0, 1, 1, 1, 1,
           0, 0, 0, 0, 1,
           0, 1, 1, 1, 0]

digitos = []
digitos.append([digit_0, [1, -1, -1, -1, -1, -1, -1, -1, -1, -1]])
digitos.append([digit_1, [-1, 1, -1, -1, -1, -1, -1, -1, -1, -1]])
digitos.append([digit_2, [-1, -1, 1, -1, -1, -1, -1, -1, -1, -1]])
digitos.append([digit_3, [-1, -1, -1, 1, -1, -1, -1, -1, -1, -1]])
digitos.append([digit_4, [-1, -1, -1, -1, 1, -1, -1, -1, -1, -1]])
digitos.append([digit_5, [-1, -1, -1, -1, -1, 1, -1, -1, -1, -1]])
digitos.append([digit_6, [-1, -1, -1, -1, -1, -1, 1, -1, -1, -1]])
digitos.append([digit_7, [-1, -1, -1, -1, -1, -1, -1, 1, -1, -1]])
digitos.append([digit_8, [-1, -1, -1, -1, -1, -1, -1, -1, 1, -1]])
digitos.append([digit_9, [-1, -1, -1, -1, -1, -1, -1, -1, -1, 1]])



import random
import matplotlib.pyplot as plt

#fixo com 10 entradas
class neuronio:
    def __init__(self):
        self.teta = 0
        self.weights = [random.randint(-1, 1)]*10
        self.b = random.randint(-1, 1)
    def output(self, input):
        value = self.b
        for i in range(0, 10):
            value += self.weights[i] *input[i]
        if value > 0:
            return 1
        return -1
    def train(self, input, target):
        out = self.output(input)
        if out != target:
            self.b += target
            for i in range(0, 10):
                self.weights[i] += target
            return 0
        return 1
        

rede = [neuronio()]*10
num_train = 10
acertos = []
while num_train > 0:
    num_train -=1
    erro = 0
    for i in range(0, 10):
        # para cada digito
        digito = digitos[i][0]
        target = digitos[i][1]
        for j in range(0, 10):
            erro += rede[j].train(digito, target[j])
    acertos.append(10-erro)


plt.plot(acertos)
plt.title("Erros ao longo do tempo")
plt.xlabel("treino")
plt.ylabel("número de erros")
plt.show()


