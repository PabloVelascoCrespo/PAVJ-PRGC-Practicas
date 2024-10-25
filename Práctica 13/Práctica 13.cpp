#include <iostream>

/*
PRÁCTICA 13
Dado el ejercicio de imágenes de la sesión 8.
    a) Implementar una función para la clase "png" que simule la eliminación del
    canal "alpha".
    b) Implementar una función que dada una tabla de imáganes de cualquier tipo
    eliminar al canal alfa de todas las que sean "png".
*/

enum class ImageType
{ 
    Generic, 
    PNG, 
    JPEG 
};

class CImage {
protected:
    ImageType type;

public:
    CImage(ImageType t) : type(t) {}

    ImageType GetType() const
    { 
        return type;
    }
    ~CImage() = default;
};

class CPng : public CImage {
public:
    CPng() : CImage(ImageType::PNG) {}

    void DestroyAlphaChannel()
    {
        printf("Canal Alpha Destruido.\n");
    }
};

class CJpeg : public CImage {
public:
    CJpeg() : CImage(ImageType::JPEG) {}
};

int main() {
    CImage* tImages[10] = { nullptr };

    tImages[0] = new CPng();
    tImages[1] = new CJpeg();
    tImages[2] = new CPng();
    tImages[3] = new CJpeg();
    tImages[4] = new CPng();
    tImages[5] = new CJpeg();
    tImages[6] = new CPng();
    tImages[7] = new CJpeg();
    tImages[8] = new CPng();
    tImages[9] = new CJpeg();

    for (int i = 0; i < 10; ++i) {
        if (tImages[i] && tImages[i]->GetType() == ImageType::PNG) {
            static_cast<CPng*>(tImages[i])->DestroyAlphaChannel();
        }
    }

    for (int i = 0; i < 10; ++i) {
        delete tImages[i];
        tImages[i] = nullptr;
    }

    return 0;
}
