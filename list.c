/*
functions:
ListNew(); -> list
ListDelete(List list); -> void
ListAddFirst(List list, T item); -> void
ListAddLast(List list, T item); -> void
LIstAdd(List list, T item, int index); -> void
ListRemoveFirst(List list); -> void
ListRemoveLast(List list); -> void
ListRemove(List list, int index); -> void
ListGetFirst() -> T
ListGetLast() -> T
ListGet(int index) -> T*/

#define concat(a,b) a ## b

#define ListNew(T) concat(T, ListNew);
#define ListDelete(T) concat(T, ListDelete);
#define ListAddLast(T) concat(T, ListAddLast);
#define ListGet(T) concat(T, ListGet);

#define defListType(T) /
    //T should be a struct /
