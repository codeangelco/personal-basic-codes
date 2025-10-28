import itertools as it
letras = set("SENDMORY")
digitos = set(range(10))

digitos -= {1}
letras -= {'M'}
permutaciones = it.permutations(digitos, len(letras))

for permu in permutaciones:
    letra_valor = dict(zip(letras, permu))
    letra_valor['M'] = 1
    send = letra_valor['S'] * 1000 + letra_valor['E'] * 100 + letra_valor['N'] * 10 + letra_valor['D']
    more = letra_valor['M'] * 1000 + letra_valor['O'] * 100 + letra_valor['R'] * 10 + letra_valor['E']
    money = letra_valor['M'] * 10000 + letra_valor['O'] * 1000 + letra_valor['N'] * 100 + letra_valor['E'] * 10 + letra_valor['Y']
    if send + more == money:
        print(f"{send} + {more} = {money}")
        print(letra_valor)
