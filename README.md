# os1-project
Projekat iz predmeta Operativni sistemi 1


Cilj ovog projekta jeste realizacija malog, ali sasvim funkcionalnog jezgra (engl. kernel)
operativnog sistema koji podržava niti (engl. multithreaded operating system) sa deljenjem
vremena (engl. time sharing). U daljem tekstu, ovakav sistem biće kratko nazivan samo
jezgrom.

U okviru ovog projekta treba realizovati alokator memorije i upravljanje nitima. Jezgro
treba da obezbedi koncept niti (engl. thread), semafora i podršku deljenju vremena (engl. time
sharing), kao i asinhronu promenu konteksta i preotimanje (engl. preemption) na prekid od
tajmera i od tastature.

Jezgro treba da bude realizovano kao „bibliotečno“, tako da korisnički program
(aplikacija) i samo jezgro dele isti adresni prostor, odnosno da predstavljaju statički povezan
jedinstven program unapred učitan u operativnu memoriju računara. Konkurentni procesi
kreirani unutar aplikacije biće zapravo samo „laki“ procesi, tj. niti (engl. thread) pokrenuti
unutar tog programa. Ovakva konfiguracija karakteristična je za ugrađene (engl. embedded)
sisteme, koji ne izvršavaju proizvoljne programe koji se učitavaju i izvršavaju na zahtev
korisnika, već izvršavaju samo onaj program (zajedno sa operativnim sistemom) koji je već
ugrađen u ciljni hardver.


Jezgro se implementira za arhitekturu procesora RISC V i školskog računara sa ovim
procesorom. Za implementaciju se može koristiti asembler za ovaj procesor i jezik C/C++.
Implementirano jezgro će se izvršavati u virtuelnom okruženju – emulatoru procesora RISC V. 
