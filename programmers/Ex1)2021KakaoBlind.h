//
// Created by momantic03 on 2021-08-24.
//

#ifndef ALGORITHM_EX1_2021KAKAOBLIND_H
#define ALGORITHM_EX1_2021KAKAOBLIND_H

std::string Pretreatment7(std::string& str)
{
    if(str.size() <= 2)
    {
       char c = str[str.size()-1];
       while(str.size() != 3)
       {
          str += c;
       }
    }
    return str;
}


std::string Pretreatment6(std::string& str)
{
    if(str.size() >= 16)
    {
        str.erase(15, str.size()-15);
        if(str[str.size()-1] == 46)
            str.erase(str.size()-1, 1);
    }
    return Pretreatment7(str);
}
// "" -> a
std::string Pretreatment5(std::string& str)
{
    if(str == "")
        str = 'a';
    return Pretreatment6(str);
}

//앞 or 뒤 . 제거
std::string Pretreatment4(std::string& str)
{
    if((int)str[0] == 46)
        str.erase(0, 1);
    if((int)str[str.size()-1] == 46)
        str.erase(str.size()-1, 1);
    return Pretreatment5(str);
}

// 연속 .. 제거
std::string Pretreatment3(std::string& str)
{
    int count = 0;
    for(int i = 0; i < str.size(); i++)
    {
        int target = (int)str[i];
        count = (target == 46) ? count+1 : 0;
        if(count == 2)
        {
            str.erase(i, 1);
            count = 0;
            i = i - 2;
        }
    }
    std::cout << str << std::endl;
    return Pretreatment4(str);
}


bool IsChar(const int start, const int end, int& target)
{
    bool is = target >= start && target <= end;
    return is;
}

// 제한 char 제거
std::string Pretreatment2(std::string& str)
{
    for(int i = 0; i < str.size(); i++)
    {
        int target_char = (int)str[i];
        int sum = IsChar(97, 122, target_char) + IsChar(48, 57, target_char) + IsChar(95, 95, target_char) + IsChar(45, 46, target_char);
        if(sum == 0)
        {
            str.erase(i, 1);
            i--;
        }
    }

    // transform + lambda
    //std::function<char(char)> func = [](char value)->char{
    //    std::string spChar = "~!@#$%^&*()=+[{]}:?,<>/";
    //    for(int i = 0 ; i < spChar.size() ; ++i)
    //    {
    //        if(value == spChar[i])
    //            return 0;
    //    }
    //    return value;
    //};
    //std::transform(str.begin(), str.end(), str.begin(), func);

    return Pretreatment3(str);
}

// 대문자 -> 소문자
std::string Pretreatment1(const std::string source_str)
{
    std::string str = source_str;
    for(int i = 0; i != str.size(); i++)
    {
        str[i] = tolower(str[i]);
    }
    return Pretreatment2(str);
}

#endif //ALGORITHM_EX1_2021KAKAOBLIND_H
