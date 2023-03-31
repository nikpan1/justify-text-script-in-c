_____________________________________________________________________________

Nikodem Panknin,	
Technologie Komputerowe II semestr.
Projekt zaliczeniowy z przedmiotu języki programowania - Justowanie tekstu.

___ ___ ___ ___ ___ ___ ___ ___ ___ ___ ___ ___ ___ ___ ___ ___ ___ ___ ___

Program wykonuje się z poziomu konsoli, poniżej schemat polecenia.

    .\justify	   [line limit length]	   [file Directory]
			arg1			arg2

    arg1 - długość do której się robi justowanie.
    arg2 - ścieżka / nazwa pliku do wyjustowania,

Przykład: .\justify plik.txt 50
Wynik justowania jest zapisywany w pliku output.txt.
___ ___ ___ ___ ___ ___ ___ ___ ___ ___ ___ ___ ___ ___ ___ ___ ___ ___ ___

- Program nie przewiduje nie prawidłowej kolejności argumentów, czy też
  wpisania argumentów o innym typie.

- Program przerwie działanie w momencie, gdy arg2 zostanie podany za mały.
  Przykładowo znajdzie się słowo w tekście dłuższe od podaneg limitu - arg2.

- Program nie zadziała poprawnie, jeżeli zostanie wykorzystany do justowania
  pliku o kodowaniu >2B.

- program nie przewiduje długości słowa > 100,
  choć większa długość nie jest problemem.

_____________________________________________________________________________


Osobiście uważam, że program został przyzwoicie zaprojektowany, 
to co w moim odczuciu brakuje to:

 - dokładniejsza obsługa błędów chociażby z wykorzystaniem perror, 

 - obsługa znaków 2B, o czym nie myślałem w momencie pisania tego programu,
   dlatego też się to nie znalazło w programie,

 - wydajniejsze zarządzanie pamięcią, chociażby w array.h.

Uznałem jednak, że celem projektu jest przedstawienie odpowiedniego poziomu
umiejętności w celu zaliczenia przedmiotu, a nieskromnie mówiąc, to choć
nie idealnie to dobrze to zrobiłem.
Jeżeli Szanowny Pan uważa inaczej, to przerobię projekt tak by reprezentował
jeszcze lepszą jakość. Liczę na code review od Pana strony, jestem ciekaw
opinii osoby bardziej doświadczonej. Chętnie przyjmę krytykę.

Z poważaniem,
Nikodem Panknin. 