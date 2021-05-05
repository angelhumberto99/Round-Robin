#ifndef MANAGER_H
#define MANAGER_H

#include <iostream>
#include "Cursor.h"
#include "Process.h"
#include <vector>
#include <time.h>
#include <stdlib.h>

class Manager {
    private:
        static const int ON_HOLD_X_POS = 0;
        static const int QUEUED_X_POS = 42;
        static const int FINISHED_X_POS = 83;
        static const int STATE_POS = 110;
        static const int DELAY = 1000;
        // procesos en el estado de NUEVO
        std::vector<Process> newProcesses;
        // procesos en el estado de LISTOS
        std::vector<Process> readyProcesses;
        // proceso en el estado de EJECUCIÓN
        Process workingProcess;
        // proceso en el estado BLOQUEDO
        std::vector<Process> blockedProcesses;
        // procesos en el estado de FINALIZADOS
        std::vector<Process> doneProcesses;

        int globalCounter;
        int totalProcess;
        char state;
        bool pause;
        bool showBCP;
        int uniqueKey;

        bool validateId(int auxInt, std::vector<int> &ids);
        bool isOperationValid(Process &auxProcess);
        void pop_front(std::vector<Process> &v);
        void printInProgress();
        void printFinished();
        void queueProcess();
        void doneProcess();
        void printQueued();
        void printBlocked();
        void selectState(char character);
        void updateBlocked();
        void createNewProcess();
        void printBCP();
    public:
        Manager() { 
            pause = false;
            showBCP = false;
            state = ' ';
            globalCounter = 0;
            uniqueKey = 1;
            workingProcess.setId(0);
            workingProcess.setTR(1);
            srand (time(NULL));
        }
        ~Manager() {}
        void printData();
        void printFinishedStatus();
        void createData();
};

#endif //MANAGER_H