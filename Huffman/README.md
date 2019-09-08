# CODIFICAÇÃO DE HUFFMAN

### O QUE É A CODIFICAÇÃO DE HUFFMAN?

A codificação de Huffman é um método de compressão que usa as probabilidades de ocorrência dos símbolos no conjunto de dados a ser comprimido para determinar códigos de tamanho variável para cada símbolo. Ele foi desenvolvido em 1952 por David A. Huffman que era, na época, estudante de doutorado no MIT, e foi publicado no artigo "A Method for the Construction of Minimum-Redundancy Codes". 

### COMO QUE FUNCIONA O PROGRAMA? 
Este programa comprime ou extrai arquivos usando a Codificação de Huffman. Na compressão, o arquivo de saída terá nos 3 primeiros bits o número correspondente à quantidade de bits de lixo no final do arquivo. Nos 13 bits
seguintes haverá o número correspondente à quantidade de bytes ocupada pe-
la árvore de Huffman. A árvore de Huffman será escrita após os dois primei-
ros bytes em pré-ordem, em codificação ASCII. Após a árvore de Huffman, ha-
verá os bits com os dados do arquivo comprimido usando a árvore impressa
como codificação. Na descompressão, as regras descritas anteriormente devem
ter sido usadas para comprimir o arquivo de entrada.
