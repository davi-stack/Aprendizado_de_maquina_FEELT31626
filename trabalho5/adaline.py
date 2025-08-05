import random
import pandas as pd
class adaline:
    def __init__(self, a):
        self.alpha = a
        self.w = []
        self.w.append(random.randint(0,100)/100.0)
        self.w.append(random.randint(0,100)/100.0)
        self.b = random.randrange(0, 100)/100.0
    def forward(self, input):
        return (self.w[0]*input[0]) + (self.w[1]*input[1]) + self.b

    def train(self, input, target):
        y_in = self.forward(input)
        error = target - y_in
        
        # Atualiza bias
        self.b += self.alpha * error
        
        # Atualiza pesos
        for i in range(len(self.w)):
            self.w[i] += self.alpha * error * input[i]
    

df = pd.read_csv("dataset.csv")
i =0
rede = adaline(0.10)
soma = 5
k = 0
while soma > 3 and k < 10 :
    k+=1
    soma = 0
    for line in df.values:
        # print(f"Caso {i} :")
        input = []
        input.append(float(line[0]))
        input.append(float(line[1]))
        output = rede.forward(input)
        soma += output - float(line[2])
        # print(f"Erro: {output - float(line[2])}")
        rede.train(input, float(line[2]))
        # print("------------------")
        # print("\n")
        i+=1

for line in df.values:
    input = []
    input.append(float(line[0]))
    input.append(float(line[1]))
    output = rede.forward(input)
    print(f"Entrada: {input} - Saida: {output} - Esperado: {float(line[2])}")
