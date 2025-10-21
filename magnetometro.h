#ifndef MAGNETOMETRO_H
#define MAGNETOMETRO_H

class magnetometro
{
public:
    magnetometro();

    bool calcularAngulo(void);



    int getValOp() const;
    void setValOp(int newValOp);
    int getValAd() const;
    void setValAd(int newValAd);

    double getAnguloRad() const;

private:
    int valOp;
    int valAd;

    double anguloRad;
};

#endif // MAGNETOMETRO_H
