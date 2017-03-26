#include "../includes/InformationPtrContainer.h"
#include "../includes/Information.h"

typedef int Key;



InformationPtrContainer::InformationPtrContainer(int size) {
	informationArray = new Information*[size];
	freeSpace = size;
	freePosition = 0;
}



InformationPtrContainer::~InformationPtrContainer() {
	delete informationArray;
}



Key InformationPtrContainer::insert (Information* infobox) {
	if (freeSpace > 0) {										// genug Platz vorhanden?
		informationArray[freePosition] = infobox;
		--freeSpace;
		++freePosition;
	} else {
		Information** oldPtr = informationArray;                // Kopie des Pointers auf das Array
		informationArray = new Information*[freePosition*2];    // Neues Array mit verdoppelter Größe
		for (int i = 0; i < freePosition; ++i) {
			informationArray[i] = oldPtr[i];                    // übertrage die alten Pointer
		}
		freeSpace = freePosition;
		delete oldPtr;
		informationArray[freePosition] = infobox;
		--freeSpace;
		++freePosition;
	}
	return (freePosition - 1);
}


Information* InformationPtrContainer::get (Key key) const {
	return informationArray[key];
}
