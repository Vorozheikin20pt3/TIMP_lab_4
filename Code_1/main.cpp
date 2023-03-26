/**  @file
*   @author Timoshchenko D.V
*  @version 1.0.0
*   @date 05.06.2021
*   @brief ������������ ���� ��� ������ modAlphaCipher
*/


#pragma once
#include <vector>
#include <string>
#include <map>
#include <locale>
#include <codecvt>
#include <iostream>
#include <cctype>
using namespace std;

/** @class modAlphaCipher
 * @author Timoshchenko D.V
 * @date 05.06.2021
 * @file modAlphaCipher.h
 * @brief ���������� ������� �����������
 * @detalies ��� ������������ � ������������� ��������� ������������� ������ encrypt � decrypt. ����� �� ��������� ���������� � �������� ���������.
 * @warnings ���������� ������ ��� �������� �����!
 */
class modAlphaCipher
{
private:
    std::string numAlpha = "�����Ũ��������������������������"; //������� �� �������
    std::string numalpha = "��������������������������������";
    wstring_convert<codecvt_utf8<wchar_t>, wchar_t> codec; //����� UTF-8
    wstring ws = codec.from_bytes(numAlpha);
    std::wstring wa = codec.from_bytes(numalpha);
    std::map <char,int> alphaNum; //������������� ������ "����� �� �������"
    std::vector <int> key; //����
    std::vector<int> convert(const std::string& s); //�������������� ������-������

    std::string convert(const std::vector<int>& v); //�������������� ������-������
    /** @brief ����� ������, ����������� ���� �� ����������
     * @param [in] s ����� �� ������� �����
     * @return result
     */
    std::string getValidOpenText(const std::string & s);
    /** @brief ����� ������, ����������� �������������� ����� �� ����������
     * @param [in] s ������������� ����� �� ������� �����
     * @return result
     */
    std::string getValidCipherText(const std::string & s);
    /** @brief ����� ������, ����������� ���� �� ����������
     * @param [in] s ����
     * @return result
     */
    std::string getValidKey(const std::string & s);
public:
    modAlphaCipher()=delete; //�������� ����������� ��� ����������
    /** @brief ����������� ��� �������� �������, ��������� � ���� ���� ����������
     * @param [in] text �������� ����� �� ������� �����
     * @warnings ���� �� ������ ���� ������ ������� � �� ������ ��������� �������. � ������ ����� ����������� ����� ���������� � �����.
     */
    modAlphaCipher(const std::string& skey); //����������� ��� ��������� �����
    /** @brief ������������
     * @param [in] text �������� ����� �� ������� �����
     * @warnings ���� �� ������ ���� ������ ������� � �� ������ ��������� �������. � ������ ����� ����������� ����� ���������� � �����.
     * @return result ������������� �����
     */
    std::string encrypt(const std::string& open_text); //������������
    /** @brief ������������
     * @param [in] text ������������� ����� �� ������� �����
     * @warnings ���� �� ������ ���� ������ ������� � �� ������ ��������� �������. � ������ ����� ����������� ����� ���������� � �����.
     * @return result ������������� �����
     */
    std::string decrypt(const std::string& cipher_text);//�������������
};

class cipher_error: public std::invalid_argument
{
public:
    explicit cipher_error (const std::string& what_arg):
        std::invalid_argument(what_arg) {}
    explicit cipher_error (const char* what_arg):
        std::invalid_argument(what_arg) {}
};