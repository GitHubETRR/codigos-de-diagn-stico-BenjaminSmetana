import random
import string

def generador_contraseña(longitud):
    #los caracteres que voy a utilizar
    letras = string.ascii_letters   #todas las letras, abc.. etc.
    numeros = string.digits         #los numeros
    simbolos = string.punctuation   #los caracteres tipo /#%$ etc..

    #Del 100% voy a utilizar un 40% letras, 40% numeros y un 20% caracteres para la contraseña.
    cant_letras = int(longitud * 0.4)
    cant_numeros = int(longitud * 0.4)
    cant_simbolos = longitud - (cant_letras + cant_numeros)  

    #genero combinaciones al azar
    parte_letras = [random.choice(letras) for _ in range(cant_letras)]
    parte_numeros = [random.choice(numeros) for _ in range(cant_numeros)]
    parte_simbolos = [random.choice(simbolos) for _ in range(cant_simbolos)]

    #uno las partes para formar la contraseña con esos digitos al azar
    contraseña = parte_letras + parte_numeros + parte_simbolos

   #mezclo el orden para que no quede todo junto.
    random.shuffle(contraseña)

   #lo convierto en texto
    return ''.join(contraseña)

#ejemplo de su uso
print(generador_contraseña(12))
