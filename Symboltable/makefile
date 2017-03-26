# Definition der Variablen

# enthaelt die Header Files
HEADERDIR = includes

# enthaelt die Source Files
SRCDIR = src

# enthaelt die Obj Files zum Testen
OBJDIR = objs

# enthaelt das ausfuehrbare File zum Testen
BINDIRTEST = debug


## hier alle Object Files eintragen, ausser das File mit der Mainmethode
## darauf achten, dass letzte Zeile ohne "\" eingetragen wird

OBJS = $(OBJDIR)/Symtable.o \
	#$(OBJDIR)/xx1.o \
	#$(OBJDIR)/xxn.o


#
#		Targets zum Bauen des Tests
#

# Variante mit geringen Makefile-Kenntnissen

## Linken der Object-Files
#makeTestSymboltable: $(OBJDIR)/Symboltable.o $(OBJDIR)/TestSymboltable.o
#	g++ -g $(OBJDIR)/Symboltable.o $(OBJDIR)/TestSymboltable.o -o $(BINDIR)/SymboltableTest
#   cp $(OBJDIR)/Symboltable.o ../projectOBJs
#
#	
## compilieren der Source-files
#
#$(OBJDIR)/Symboltable.o :  $(SRCDIR)/Symboltable.cpp $(HEADERDIR)/Symboltable.h
#	@echo "g++ $*.cpp"
#	g++ -g  -c -Wall  -o $(OBJDIR)/Symboltable.o  $(SRCDIR)/Symboltable.cpp
#
#
#$(OBJDIR)/TestSymboltable.o :  $(SRCDIR)/TestSymboltable.cpp $(SRCDIR)/Symboltable.h
#	@echo "g++ $*.cpp"
#	g++ -g  -c -Wall  -o $(OBJDIR)/TestSymboltable.o  $(SRCDIR)/TestSymboltable.cpp
#


# Variante mit guten Makefile-Kenntnissen

makeTestSymboltable: SymtableTarget TestSymtableTarget
	g++ -g $(OBJDIR)/*.o $(BINDIRTEST)/TestSymboltable.o  -o $(BINDIRTEST)/SymboltableTest

SymtableTarget: $(SRCDIR)/Symtable.cpp $(HEADERDIR)/Symtable.h
	g++ -g -c -Wall $(SRCDIR)/Symtable.cpp -o $(OBJDIR)/Symtable.o 

InformationTarget: $(SRCDIR)/Information.cpp $(HEADERDIR)/Information.h
	g++ -g -c -Wall $(SRCDIR)/Information.cpp -o $(OBJDIR)/Information.o
	
ListTarget: $(SRCDIR)/List.cpp $(HEADERDIR)/List.h $(HEADERDIR)/SymtabEntry.h 
	g++ -g -c -Wall $(SRCDIR)/List.cpp -o $(OBJDIR)/List.o
	
StringTabTarget: $(SRCDIR)/StringTab.cpp $(HEADERDIR)/StringTab.h
	g++ -g -c -Wall $(SRCDIR)/StringTab.cpp -o $(OBJDIR)/StringTab.o
	
InformationPtrContainerTarget: $(SRCDIR)/InformationPtrContainer.cpp $(HEADERDIR)/InformationPtrContainer.h
	g++ -g -c -Wall $(SRCDIR)/InformationPtrContainer.cpp -o $(OBJDIR)/InformationPtrContainer.o
	
SymtabEntryTarget: $(SRCDIR)/SymtabEntry.cpp $(HEADERDIR)/SymtabEntry.h $(HEADERDIR)/Information.h
	g++ -g -c -Wall $(SRCDIR)/SymtabEntry.cpp -o $(OBJDIR)/SymtabEntry.o

# $@ name des object files = name auf der linken Seite vom Doppelpunkt des Targets
# $< erste abhaengigkeit, $< das erste Element in der Liste der Abhaengigkeiten
# $@ --> linke Seite vom Doppelpunkt
# $^ --> rechte Seite vom Doppelpunkt

$(OBJDIR)/%.o :  $(SRCDIR)/%.cpp $(HEADERDIR)/%.h
	g++ -g  -c -Wall  $<  -o $@



TestSymboltableTarget: $(SRCDIR)/TestSymtable.cpp $(HEADERDIR)/Symtable.h
	g++ -g  -c -Wall $(SRCDIR)/TestSymtable.cpp -o $(BINDIRTEST)/TestSymtable.o  
	


# loeschen aller files im verzeichnis $(OBJDIR) und $(BINDIRTEST) und neu compilieren

cleanSymtable:
	rm -rf $(OBJDIR)/*.o
	rm -rf $(BINDIRTEST)/*
	
	
	
## objs fuer GesamtProjekt neu erzeugen
SymboltableOBJTarget:
	$(MAKE) SymtableTarget
	$(MAKE) InformationTarget
	$(MAKE) ListTarget
	$(MAKE) StringTabTarget
	$(MAKE) InformationPtrContainerTarget
	$(MAKE) SymtabEntryTarget

	