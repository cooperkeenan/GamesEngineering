import subprocess
import os

def run_invaders():
    try:
        while True:
            # Running 'make'
            os.system('make')

            # Running the game and allowing interaction
            process = subprocess.Popen(['./bin/2_INVADERS'], stdin=subprocess.PIPE)
            
            # Asking to rerun or quit without closing the game window
            rerun = input("Press Enter to run again or type 'q' to quit: ").strip().lower()
            if rerun == 'q':
                process.terminate()
                break
            else:
                process.terminate()
    except KeyboardInterrupt:
        print("\nExiting the program.")

if __name__ == "__main__":
    run_invaders()