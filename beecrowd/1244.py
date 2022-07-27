if __name__ == "__main__":
    n:int
    n = int(input())

    while n>0:
        exp = input()
        palavras = exp.split()

        for i in range(len(palavras)):
            palavras[i] = (palavras[i],len(palavras[i]))

        palavras.sort(reverse=True, key=lambda y: y[1])

        for i in range(len(palavras)):

            if i != len(palavras) - 1:
                print(f"{palavras[i][0]}", end=" ")
            else:
                print(palavras[i][0])

        n -=1