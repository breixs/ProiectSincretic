# ProiectSincretic - Brei Paul, Grupa 1.1, An II

Acesta este proiectul sincretic realizat pentru Problema Celor 8 Regine. Am folosit limbajul de programare C++ pentru rezolvarea problemei datorita faptului ca sunt familiar cu acesta. 
In plus, C++ este un limbaj rapid cu ajutorul caruia se pot crea aplicatii bine optimizate.

Aplicatia rezolva Problema Celor 8 Regine si ofera utilizatorului doua posibilitati: 1. Afisarea Celor 92 de solutii pentru Problema Reginelor. 2. Afisarea unei singure solutii aleatorii pentru Problema Reginelor.
Reginele sunt reprezentate de cifra "1" pe o tabla de sah in care celelalte spatii libere sunt reprezentate de cifra "0".

Descrierea Functiilor Programului:
-creareTabla: Aceasta prima functie este cea mai simpla dintre toate si este utilizata pentru a crea o tabla goala de sah(fiecare element a matricei este setat pe 0).
-afisareTabla: O alta functie simpla folosita pentru a afisa solutiile problemei. Aceste solutii sunt stocate intr-un vector de solutii iar functia pur si simplu parcurge vectorul, afisand fiecare element.
-afisareRandom: Functie asemanatoare celei anterioare dar folosita pentru afisarea unei singure solutii aleatorii pentru Problema Reginelor. Functioneaza intr-un fel asemanator cu cea anterioara: parcurge vectorul de solutii in acelasi mod dar afiseaza solutia doar in cazul in care numarul solutii(reprezentat de variabila contor) corespunde cu numarul ales aleatoriu de catre program.
-esteValid: Functie absolut esentiala programului. Aceasta verifica daca exista un loc in care se poate plasa o regina pe tabla. Initial verifica acelasi rand al tablei la care se afla programul in momentul apelarii functiei, apoi verifica cele doua diagonale. Daca se gaseste o pozitie valida, functia returneaza "true", iar in caz contrar, functia returneaza "false".
-rezolvare: Functia care rezolva problema intr-un mod recursiv. Primul caz prezent in functie este cel de baza(base case), care se executa odata ce toata coloanele au fost explorate. Acesta adauga solutiile valide gasite in vectorul de solutii. Al doilea caz este reprezentat de cel recursiv. Acesta incepe prin a incerca sa puna o regina pe fiecare rand al fiecarei coloane. Programul se foloseste de functia "esteValid" pentru a vedea daca locul in care incearca sa puna regina este permis sau nu. Daca da, marcheaza locul si trece la urmatoarea coloana(functia este apelata din nou schimand parametrul: "col+1"). Daca nu gaseste niciun loc permis, programul sterge regina din pozitia ei actuala si incearca urmatorul rand.
-functia Main: in functia main este prezent meniul prezentat utilizatorului unde se apeleaza functiile corespunzatoare alegerilor utilizatorului. Tot in aceasta functie main este prezenta si o tratarea a unei exceptii. Aceasta este prezenta pentru ca programul sa continue sa functioneze si in cazul in care utilizatorul introduce o optiune nepermisa(ori un numar diferit de 0, 1, 2, ori un caracter in loc de cifra).

Aceasta este versiunea finala a programului. Toate versiunile anterioare pot fi accesate folosind istoria commit-urilor din acest repository.

