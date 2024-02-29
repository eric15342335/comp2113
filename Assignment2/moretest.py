import random

characters = []
for i in range(0, random.randint(5,100)):
    choose_case = random.choice([0, 32])
    characters.append(chr(random.randint(65+choose_case, 90+choose_case)))
characters += ["!"]

while True:
    a = random.randint(3,500)
    if a%2 == 1 and a%13 == 1:
        key1 = a
        break
key2 = random.randint(1,100)
print("e", key1, key2, " ".join(characters))
