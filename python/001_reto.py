import random
import os

class Jugador:
    def __init__(self, nombre : str = "Jugador"):
        self.nombre = nombre
        self.puntaje = dict.fromkeys(("victorias","derrotas","empates"), 0)

class Juego:
    def __init__(self, jugador : Jugador = Jugador()):
        self.jugador = jugador
        self.partidas_jugadas = 0
        self.juagadas = {
            1: "Piedra",
            2: "Papel",
            3: "Tijera",
            4: "Lagarto",
            5: "Spock"
        }


    def imprimir_resultado(self, puntajes : dict) -> str:
        return f"\n\tVictorias: {puntajes['victorias']}\n\tDerrotas: {puntajes['derrotas']}\n\tEmpates: {puntajes['empates']}"


    def jugada(self, jugada_p1: str, jugada_p2: str) -> int:
        if jugada_p1 == jugada_p2:
            return 0
        if (jugada_p1 == "Piedra" and (jugada_p2 == "Tijera" or jugada_p2 == "Lagarto")) \
        or (jugada_p1 == "Papel" and (jugada_p2 == "Piedra" or jugada_p2 == "Spock")) \
        or (jugada_p1 == "Tijera" and (jugada_p2 == "Papel" or jugada_p2 == "Lagarto")) \
        or (jugada_p1 == "Lagarto" and (jugada_p2 == "Spock" or jugada_p2 == "Papel")) \
        or (jugada_p1 == "Spock" and (jugada_p2 == "Tijera" or jugada_p2 == "Piedra")):
            return 1
        return -1

        
    def final(self) -> None:
        os.system("cls" if os.name == "nt" else "clear")
        print("\t¡Juego terminado!")
        if self.jugador.puntaje["victorias"] > self.jugador.puntaje["derrotas"]:
            print(f"Felicitaciones {self.jugador.nombre}!\nTu marcador es:", self.imprimir_resultado(self.jugador.puntaje))
        else:
            print(f"Mejor suerte la proxima {self.jugador.nombre}!\nTu marcador es:", self.imprimir_resultado(self.jugador.puntaje))
    
    
    def menu(self, finito : bool = False) -> None:
        menu = {
            0: "0. Terminar",
            1: "1. Piedra",
            2: "2. Papel",
            3: "3. Tijera",
            4: "4. Lagarto",
            5: "5. Spock",
        }
        for opcion in menu:
            if opcion == 0 and finito:
                continue
            print(menu[opcion])
            
            

def main():
    try:
        print("\t¡Pedra, Papel y Tijera! Con... Lagarto? Y Spock??!!")
        nombre = input("Ingresa tu nombre: ")
        juego = Juego(Jugador(nombre))
        cantidad_rondas = 0
        while cantidad_rondas != 1 and cantidad_rondas != 2:
            cantidad_rondas = int(input("Jugar rondas ilimitadas (1) o cierta cantidad de rondas (2)?: "))
        if cantidad_rondas == 2:
            cantidad_rondas = int(input("Digite la cantidad de rondas a jugar: "))
            if cantidad_rondas < 1:
                print("Error: Juego no iniciado correctamente")
                return
        else:
            cantidad_rondas = -1
        while True:
            if cantidad_rondas == 0:
                juego.final()
                break
            juego.menu()
            decision = int(input("Ingresa tu opcion: "))
            if decision == 0:
                cantidad_rondas = 0
                continue
            maquina = random.randrange(1,6)
            print(f"Bot eligio {juego.juagadas[maquina]}")
            ds = juego.jugada(juego.juagadas[decision],juego.juagadas[maquina])
            if ds == 1:
                juego.jugador.puntaje["victorias"] += 1
            elif ds == 0:
                juego.jugador.puntaje["empates"] += 1
            else:
                juego.jugador.puntaje["derrotas"] += 1
            if cantidad_rondas > 0:
                cantidad_rondas -= 1
    except Exception as ex:
        print("¡ERROR!")
        print("Nombre:", type(ex).__name__)
        print("Mensaje:", ex.args[0])
        os.system("pause")
        os.system("cls" if os.name == "nt" else "clear")
        main()


os.system("cls" if os.name == "nt" else "clear")
main()