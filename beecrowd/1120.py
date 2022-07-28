
if __name__ == "__main__":

    inp = input()

    while inp != "0 0":
        x = inp.split()
        y = x[1]

        z = ""
        is0 = True

        for i in y:
            if i != x[0]:
                is0 = False
                z += i

        if is0:
            print(0)
        else:
            z = int(z)
            print(z)



        inp = input()