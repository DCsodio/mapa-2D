#ifndef MAGNETOMETRO_H
#define MAGNETOMETRO_H

class magnetometro
{
public:
    magnetometro();

    float getAnguloDeg() const;
    void setAnguloDeg(float _angulo);

private:
    float anguloDeg;
};

#endif // MAGNETOMETRO_H
