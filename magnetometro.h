#ifndef MAGNETOMETRO_H
#define MAGNETOMETRO_H

class magnetometro
{
public:
    magnetometro();

    float getAnguloDeg() const;
    void setAnguloDeg(float _angulo);

    bool getInicializado() const;
    void setInicializado(bool newInicializado);

private:
    float anguloDeg;
    bool inicializado;
};

#endif // MAGNETOMETRO_H
