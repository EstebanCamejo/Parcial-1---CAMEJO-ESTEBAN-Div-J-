int controller_loadFromText(char* path , LinkedList* pArrayListPassenger);
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger);
int controller_addPassenger(LinkedList* pArrayListPassenger);
int controller_editPassenger(LinkedList* pArrayListPassenger);
int controller_removePassenger(LinkedList* pArrayListPassenger);
int controller_ListPassenger(LinkedList* pArrayListPassenger);
int controller_sortPassenger(LinkedList* pArrayListPassenger);
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger);
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger);

int controller_GuardarSiguienteID (int id);
int controller_SiguienteId(LinkedList* pArrayListPassenger);
//int controller_printPassenger (Passenger* pPassenger);
int controller_ListPassengerStatic(LinkedList* pArrayListPassenger);
int controller_getMaximoId(LinkedList* pArrayListPassenger);
int controller_ValidarId (LinkedList* pArrayListPassenger, int id);

int controller_Map (LinkedList*listaServicios);
void calcular(void* pElemento);
float multiplicar (int cantidad, float precio);
//eServicios* filtrar (void* pElemento , LinkedList* listaServicios);
