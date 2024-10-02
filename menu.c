int checkStrongPassword(char* password)
{
    int check1, check2, check3, check4;
    check1 =0; check2=0; check3=0; check4=0;
    int length=0;
    for (int i=0;password[i]!='0';i++)
    {
        if(isdigit(password[i])) check1=1;
        if(islower(password[i])) check2=1;
        if(isupper(password[i])) check3=1;
        if(ispunct(password[i])) check4=1;
        length ++;
    }
    return length >= 6 && check1 && check2 && check3 && check4;

}
