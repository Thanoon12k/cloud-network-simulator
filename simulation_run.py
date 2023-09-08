import subprocess
import os
def runSimulation():
        os.chdir("D:/omnetpp/omnetpp-4.6/samples/fogsimulation2")
        bash_path = "C:/Program Files/Git/bin/bash.exe"
        script_path = "D:/omnetpp/omnetpp-4.6/samples/fogsimulation2/runy.sh"
        result = subprocess.run([bash_path, script_path])
        if result.returncode == 0:
            print("Script ran successfully!")
        else:
            print(f"Script exited with code {result.returncode}")


