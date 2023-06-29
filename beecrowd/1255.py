n = int(input())

while n > 0:
    biggest = 0
    letters = {}

    string = input()
    for char in string:
        if char.isalpha():
            char = char.lower()
            if char in letters:
                letters[char] += 1
                if letters[char] > biggest:
                    biggest += 1
            else:
                letters[char] = 1
                if letters[char] > biggest:
                    biggest += 1

    ans = ''
    keys = list(letters.keys())
    keys.sort()
    letters = {i: letters[i] for i in keys}

    for letter in letters:
        if letters[letter] == biggest:
            ans = ans + letter

    print(ans)
    n -= 1

