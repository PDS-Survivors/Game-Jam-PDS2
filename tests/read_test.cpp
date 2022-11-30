#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../third_party/doctest.h"
#include "../include/namespaces/reader.hpp"

TEST_CASE("Teste de unidade - readfile")
{
    SUBCASE("Caso positivo: Leitura de arquivo com êxito")
    {
        std::vector<int> v; std::vector<std::string> w; std::vector<std::string> f;
        CHECK_NOTHROW(read::readfile("../lib/npcs/lelaq.txt", v, w, f));
    }
    SUBCASE("Caso negativo: Leitura de arquivo inexistente")
    {
        std::vector<int> v; std::vector<std::string> w; std::vector<std::string> f;
        CHECK_THROWS(read::readfile("../lib/npcs/naoexiste.txt", v, w, f));
    }
    SUBCASE("Caso negativo: Leitura de arquivo com formato não suportado")
    {
        std::vector<int> v; std::vector<std::string> w; std::vector<std::string> f;
        CHECK_NOTHROW(read::readfile("../tests/teste.txt", v, w, f));
    }
}

TEST_CASE("Teste de unidade - readint")
{
    SUBCASE("Caso postivo: numero positivo")
    {
        std::string::iterator it;
        std::string line = "01_";
        CHECK_EQ(10, read::readint(it, line));
    }
    SUBCASE("Caso especial: numero negativo")
    {
        std::string::iterator it;
        std::string line = "01-_";
        CHECK_EQ(-10, read::readint(it, line));
    }
    SUBCASE("Caso negativo: formato errado")
    {
        std::string::iterator it;
        std::string line = "10_";
        CHECK_EQ(10, read::readint(it, line));
    }
}

TEST_CASE("Teste de unidade - readstring")
{
    SUBCASE("Caso positivo")
    {
        std::string::iterator it;
        std::string line = "string de teste_";
        CHECK_EQ("string de teste", read::readint(it, line));
    }
    SUBCASE("Caso negativo")
    {
        std::string::iterator it;
        std::string line = "string de teste";
        CHECK_EQ("string de teste", read::readint(it, line));
    }
}