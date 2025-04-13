double julianDate(struct ptm ptm) {
    int Y = ptm.year;
    int M = ptm.month;
    int D = ptm.day;
    int h = ptm.hour;
    int m = ptm.min;
    int s = ptm.sec;
    long ns = ptm.ns;

    if (M <= 2) {
        Y--;
        M += 12;
    }

    // Calcul des constantes A et B
    int A = (int)floor((double)Y / 100);
    int B = 2 - A + (int)floor((double)A / 4);

    // Conversion des nanosecondes en fraction de seconde
    double fractional_seconds = (double)ns / 1e9;

    // Calcul de la fraction temporelle
    double time_fraction = (h + (m + (s + fractional_seconds) / 60.0) / 60.0) / 24.0;

    // Calcul du Julian Date
    double JJ = floor(365.25 * (Y + 4716)) + floor(30.6001 * (M + 1)) + D + time_fraction + B - 1524.5;

    return JJ;
}