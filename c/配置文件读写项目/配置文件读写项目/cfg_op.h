#pragma once
int GetCfgItem(char* pFileName, char* pKey, char* pValue, int* pValueLen);
int WriteCfgItem(char* pFileName, char* pItemName, char* pItemValue, int itemValueLen);