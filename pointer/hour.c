void decoupeMinutes(int *heures, int *minutes)
{
    *heures = *minutes / 60;  // 90 / 60 = 1
    *minutes = *minutes % 60; // 90 % 60 = 30
}
