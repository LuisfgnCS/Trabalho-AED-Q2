#define MAX 22
// structs --------------------------------------------------------------------------------
typedef struct Paciente{
    char nome[20];
    int urgencia[4];
} paciente;

typedef struct Heap {
    int max;
    int pos; 
    paciente *pacientes; 
} heap;

// fun��es --------------------------------------------------------------------------------
heap* heap_cria(); // cria uma nova arvore.
int inserir(heap* hospital, paciente novo); // insere e reajusta um novo elemento no heap.
paciente heap_remove(heap* hospital); // remove a raiz do heap e reajusta.
void print_heap(heap* hospital); // printa o heap.
