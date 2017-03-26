# Definition der Variablen

# enthaelt die Header Files
HEADERDIR = includes

# enthaelt die Source Files
SRCDIR = src

# enthaelt die Obj Files fuer das Gesamtprojekt
OBJDIR = objs

# enthaelt die Objectfiles und das ausfuehrbare File zum Testen des Teilprojekts
BINDIRTEST = debug
#
#		Targets zum Bauen des Tests
#

# Linken der Object-files, abhaengig von AutomatTarget und TestAutomatTarget
# flag:
# -g --> debug Informationen erzeugen
# -o --> name des output-files

makeTestAutomat:BufferTarget StateTarget AutomatTarget TestAutomatTarget ScannerTarget
	g++ -g objs/State.o objs/Automat.o ../Scanner/objs/Scanner.o ../Buffer/objs/Buffer.o debug/TestAutomat.o -o debug/AutomatTest
	
	
# compilieren des Files Automat.cpp zu Automat.o, 
# das Objekt-File ist abhängig von src/Automat.cpp und src/Automat.h
# flag:
# -c --> nur compilieren
# -g --> debug Informationen erzeugen
# -Wall --> alle meldungen erzeugen (Warning all)
clean:
	rm -f $(AUTOMATDIR)/$(OBJDIR)/*.o


BufferTarget: ../Buffer/src/Buffer.cpp ../Buffer/includes/Buffer.h 
	g++ -g -c -Wall ../Buffer/src/Buffer.cpp -o ../Buffer/objs/Buffer.o

StateTarget: src/State.cpp includes/State.h includes/Automat.h
	g++ -g -c -Wall src/State.cpp -o objs/State.o
	
ScannerTarget: ../Scanner/src/Scanner.cpp ../Scanner/includes/Scanner.h ../Scanner/includes/IScanner.h
	g++ -g -c -Wall ../Scanner/src/Scanner.cpp -o ../Scanner/objs/Scanner.o
	

AutomatTarget :  src/Automat.cpp includes/Automat.h includes/State.h
	g++ -g  -c -Wall src/Automat.cpp -o objs/Automat.o  


# TestAutomat.o ist abhängig von src/TestAutomat.cpp und src/Automat.h
TestAutomatTarget :  src/TestAutomat.cpp includes/Automat.h
	g++ -g  -c -Wall src/TestAutomat.cpp  -o debug/TestAutomat.o  



# loeschen aller files im verzeichnis obj und debug, dann neu erzeugen

cleanAutomat:
	rm -f objs/*.o
	rm -f debug/*
	$(MAKE) makeTestAutomat
	
	
# dieses Target wird vom makefile des Gesamtprojekts verwendet
# objs fuer Gesamtprojekt loeschen und dann neu erzeugen
AutomatOBJTarget:
	$(MAKE) AutomatTarget
	$(MAKE) StateTarget

