/**  @file
* *  @author ��������� �.�
* *  @version 1.0.0
* *  @date 05.06.2021
* *  @brief ������������ ���� ��� ������ modAlphaCipher
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
 ** @author ��������� �.�
 ** @date 05.06.2021
 ** @file modAlphaCipher.h
 ** @brief ���������� ������� ���������� ������������
 ** @detalies ��� ������������ � ������������� ��������� ������������� ������ encrypt � decrypt. ����� �� ��������� ���������� �� ������ ��������. �������� ������ ���������� ���������.
 ** @warnings ���������� ������ ��� ����������� �����!
 */

class modAlphaCipher
{
private:
    int key;
    /** @brief ����� ������, ����������� ���� �� ����������
     ** @param [in] s ����� �� ������� �����
     ** @return result
     */
    std::string getValidOpenText(const std::string & s);
    /** @brief ����� ������, ����������� �������������� ����� �� ����������
     ** @param [in] s ������������� ����� �� ���������� �����
     ** @return result
     */
    std::string getValidCipherText(const std::string & s);
public:
    modAlphaCipher()=delete;
    modAlphaCipher(const string& key1);
    /** @brief ������������
     ** @param [in] text �������� ����� �� ���������� �����
     ** @warnings ���� �� ������ ���� ������ ������� � �� ������ ��������� �������. � ������ ����� ����������� ����� ���������� � �����.
     ** @return result ������������� �����
     ** @throw cipher_error ���� � �������� ������ ������ ������ ������
     */
    std::string encrypt(const std::string& open_text);
    /** @brief �������������
     ** @param [in] text ������������� ����� �� ���������� �����
     ** @warnings ���� �� ������ ���� ������ ������� � �� ������ ��������� �������. � ������ ����� ����������� ����� ���������� � �����.
     ** @return result �������������� �����
     ** @throw cipher_error ���� � �������� ������ ������ ������ ������
     */
    std::string decrypt(const std::string& cipher_text);
};
    /** @class cipher_error
     ** @file modAlphaCipher.h
     ** @brief ����� ������ ���������� 
     */
class cipher_error: public std::invalid_argument
{
public:
    /** @brief ��������� ������
     ** @param [in] what_arg ����� �������� ������ ��� ������ getValidText, ���� ������������ �������� �������� ����������, ������� ������ ���������� ���������� � �������� ��������� �������.
     ** @warnings ���� �� ������ ���� ������ ������� � �� ������ ��������� �������. � ������ ����� ����������� ����� ���������� � �����.
     ** @return result �������������� �����
     ** @throw cipher_error ���� � �������� ������ ������ ������ ������
     */
    explicit cipher_error (const std::string& what_arg):
        std::invalid_argument(what_arg) {}
    /** @brief ��������� ������
     ** @param [in] what_arg ����� �������� ������ ��������, ���� ������������ �������� �������� ����������, ������� ������ ���������� ���������� � �������� ��������� �������.
     ** @warnings ���� �� ������ ���� ������ ������� � �� ������ ��������� �������. � ������ ����� ����������� ����� ���������� � �����.
     ** @return result �������������� �����
     ** @throw cipher_error ���� � �������� ������ ������ ������ ������
     */
    explicit cipher_error (const char* what_arg):
        std::invalid_argument(what_arg) {}
};