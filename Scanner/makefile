# Definition der Variablen

# enthaelt die Header Files
HEADERDIR = includes

# enthaelt die Source Files
SRCDIR = src

# enthaelt die Obj Files zum Testen
OBJDIR = objs

# enthaelt das ausfuehrbare File zum Testen
BINDIRTEST = debug


AUTOMATDIR = ../Automat

BUFFERDIR = ../Buffer

SYMBOLTABLEDIR = ../Symboltable


## hier alle Object Files eintragen, ausser das File mit der Mainmethode
## darauf achten, dass letzte Zeile ohne "\" eingetragen wird

OBJS = $(OBJDIR)/Scanner.o \
	#$(OBJDIR)/xx1.o \
	#$(OBJDIR)/xxn.o

##g++ -g $(OBJDIR)/Scanner.o $(OBJDIR)/TestScanner.o   $(PROJECTOBJDIR)/Automat/*.o $(PROJECTOBJDIR)/Buffer/*.o $(PROJECTOBJDIR)/Symboltable/*.o -o $(BINDIRTEST)/ScannerTest

## Variante mit wenig Makefile-Kenntnissen
# 
## linken der Object-files 
makeTestScanner: ScannerTarget TestScannerTarget
	g++ -g $(BINDIRTEST)/TestScanner.o $(OBJDIR)/*.o $(AUTOMATDIR)/$(OBJDIR)/*.o $(BUFFERDIR)/$(OBJDIR)/*.o $(SYMBOLTABLEDIR)/$(OBJDIR)/*.o -o $(BINDIRTEST)/ScannerTest
##	
##	
##	
### compilieren der source-files
#$(OBJDIR)/Scanner.o :  $(SRCDIR)/Scanner.cpp $(HEADERDIR)/Scanner.h
#	@echo "g++ $*.cpp"
#	g++ -g  -c -Wall  -o $(OBJDIR)/Scanner.o  $(SRCDIR)/Scanner.cpp
#	cp $(OBJDIR)/Scanner.o $(PROJECTOBJDIR)/Scanner
##
#$(OBJDIR)/TestScanner.o :  $(SRCDIR)/TestScanner.cpp 
#	@echo "g++ $*.cpp"
#	g++ -g  -c -Wall  -o $(OBJDIR)/TestScanner.o  $(SRCDIR)/TestScanner.cpp
#
	
	
# Variante mit guten Makefile-Kenntnissen
#makeTestScanner: $(MAKE) -c ScannerTest

ScannerOBJTarget:
	$(MAKE) ScannerTarget

ScannerTarget: src/Scanner.cpp includes/Scanner.h includes/IScanner.h ../Automat/includes/TokenClass.h ../Automat/includes/TokenType.h includes/Utility.h
	g++ -g -c -Wall src/Scanner.cpp -o objs/Scanner.o



# 
# $@ name des object files
# $< erste abhaengigkeit


TestScannerTarget: $(SRCDIR)/TestScanner.cpp $(HEADERDIR)/Scanner.h
	g++ -g  -c -Wall src/TestScanner.cpp -o $(BINDIRTEST)/TestScanner.o  
	

# loeschen aller files im verzeichnis $(OBJDIR) und $(BINDIRTEST) und neu erstellen

cleanScanner:
	rm -rf $(OBJDIR)/*.o
	rm -rf $(BINDIRTEST)/*
#	$(MAKE) makeTestScanner


