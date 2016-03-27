#include "bigdata.h"
#include <cassert>

BigData::BigData(INT64 data)
: m_llValue(data)
, m_strData("")
{
	INT64ToString();
}

BigData::BigData(const char *_pData)
{ 
	assert(NULL != _pData);

	char cSybom = _pData[0];
	char* pData = (char*)_pData;
	if ('+' == cSybom || '-' == cSybom)
	{
		pData++;
	}
	else if (*pData >= '0' && *pData <= '9')
	{
		cSybom = '+';
	}
	else
	{
		m_llValue = 0;
		m_strData = "0";
		return;
	}

	 
	while ('0' == *pData)
		pData++;

	 
	m_strData.resize(strlen(pData) + 1);
	m_llValue = 0;
	m_strData[0] = cSybom;
	int iCount = 1;
	while (pData)
	{
		if (*pData >= '0' && *pData <= '9')
		{
			m_llValue = m_llValue * 10 + *pData - '0';
			m_strData[iCount++] = *pData++;
		}
		else
		{
			break;
		}
	}

	m_strData.resize(iCount);

	if ('-' == cSybom)
	{
		m_llValue = 0 - m_llValue;
	}
}

BigData BigData::operator+(BigData& bigData)
{
	 
	if (!IsINT64Owerflow() && !bigData.IsINT64Owerflow())
	{
		if (m_strData[0] != bigData.m_strData[0])
		{
			return BigData(m_llValue + bigData.m_llValue);
		}
		else
		{
			 
			if (('+' == m_strData[0] && MAX_INT64 - m_llValue >= bigData.m_llValue) ||
				('-') == m_strData[0] && MIN_INT64 - m_llValue <= bigData.m_llValue)
			{
				return BigData(m_llValue + bigData.m_llValue);
			}
		}
	}

	 
	std::string strRet;
	if (m_strData[0] == bigData.m_strData[0])
	{
		strRet = Add(m_strData, bigData.m_strData);
	}
	else
	{

	}

	return BigData(strRet.c_str());
}

BigData BigData::operator-(const BigData& bigData)
{
	if (!IsINT64Owerflow() && !bigData.IsINT64Owerflow())
	{
		if (m_strData[0] == bigData.m_strData[0])
		{
			return BigData(m_llValue - bigData.m_llValue);
		}
		else
		{
			 
			if (('+' == m_strData[0] && MAX_INT64 + bigData.m_llValue >= m_llValue) ||
				('-' == m_strData[0] && MIN_INT64 + bigData.m_llValue <= m_llValue))
			{
				return BigData(m_llValue - bigData.m_llValue);
			}
		}
	}

	 
	std::string strRet;
	if (m_strData[0] != bigData.m_strData[0])
	{
		strRet = Add(m_strData, bigData.m_strData);
	}
	else
	{
		strRet = Sub(m_strData, bigData.m_strData);
	}
	return BigData(strRet.c_str());
}

BigData BigData::operator*(const BigData& bigData)
{
	if (0 == m_llValue || 0 == bigData.m_llValue)
	{
		return BigData(INT64(0));
	}

	if (!IsINT64Owerflow() && !bigData.IsINT64Owerflow())
	{
		if (m_strData[0] == bigData.m_strData[0])
		{
			 
			if (('+' == m_strData[0] && MAX_INT64 / m_llValue >= bigData.m_llValue) ||
				('-' == m_strData[0] && MAX_INT64 / m_llValue <= bigData.m_llValue))
			{
				return BigData(m_llValue*bigData.m_llValue);
			}
		}
		else
		{
			 
			if (('+' == m_strData[0] && MIN_INT64 / m_llValue <= bigData.m_llValue) ||
				('-' == m_strData[0] && MIN_INT64 / m_llValue >= bigData.m_llValue))
			{
				return BigData(m_llValue*bigData.m_llValue);
			}
		}
	}

	return BigData(Mul(m_strData, bigData.m_strData).c_str());
}

std::string BigData::Add(std::string left, std::string right)
{
	int iLSize = left.size();
	int iRSize = right.size();
	if (iLSize < iRSize)
	{
		std::swap(left, right);
		std::swap(iLSize, iRSize);
	}

	std::string strRet;
	strRet.resize(iLSize + 1);
	strRet[0] = left[0];
	char cStep = 0;

	 
	for (int iIdx = 1; iIdx < iLSize; ++iIdx)
	{
		char cRet = left[iLSize - iIdx] - '0' + cStep;

		if (iIdx < iRSize)
		{
			cRet += (right[iRSize - iIdx] - '0');
		}

		strRet[iLSize - iIdx + 1] = (cRet % 10 + '0');
		cStep = cRet / 10;
	}

	strRet[1] = (cStep + '0');

	return strRet;
}

std::string BigData::Sub(std::string left, std::string right)
{
	 
	int iLSize = left.size();
	int iRSize = right.size();
	char cSymbol = left[0];
	if (iLSize < iRSize ||
		(iLSize == iRSize && left < right))
	{
		std::swap(left, right);
		std::swap(iLSize, iRSize);
		if ('+' == cSymbol)
		{
			cSymbol = '-';
		}
		else
		{
			cSymbol = '+';
		}
	}


	std::string strRet;
	strRet.resize(iLSize);
	strRet[0] = cSymbol;
 
	for (int iIdx = 1; iIdx < iLSize; iIdx++)
	{
		char cRet = left[iLSize - iIdx] - '0';
		if (iIdx < iRSize)
		{
			cRet -= (right[iRSize - iIdx] - '0');
		}

		if (cRet < 0)
		{
			left[iLSize - iIdx - 1] -= 1;
			cRet += 10;
		}

		strRet[iLSize - iIdx] = (cRet + '0');
	}

	return strRet;
}

std::string BigData::Mul(std::string left, std::string right)
{
	int iLSize = left.size();
	int iRSize = right.size();
	if (iLSize > iRSize)
	{
		std::swap(left, right);
		std::swap(iLSize, iRSize);
	}

	char cSymbol = '+';
	if (left[0] != right[0])
	{
		cSymbol = '-';
	}

	std::string strRet;
	 
	strRet.assign(iLSize + iRSize - 1, '0');
	strRet[0] = cSymbol;
	int iDataLen = strRet.size();
	int iOffset = 0;

	for (int iIdx = 1; iIdx < iLSize; ++iIdx)
	{
		char cLeft = left[iLSize - iIdx] - '0';
		char cStep = 0;
		if (0 == cLeft)
		{
			iOffset++;
			continue;
		}

		for (int iRIdx = 1; iRIdx < iRSize; ++iRIdx)
		{
			char cRet = cLeft*(right[iRSize - iRIdx] - '0');
			cRet += cStep;
			cRet += (strRet[iDataLen - iOffset - iRIdx] - '0');
			strRet[iDataLen - iOffset - iRIdx] = cRet % 10 + '0';
			cStep = cRet / 10;
		}

		strRet[iDataLen - iOffset - iRSize] += cStep;
		iOffset++;
	}

	return strRet;
}

void BigData::INT64ToString()
{
	 
	char cSymbol = '+';
	INT64 temp = m_llValue;
	if (temp < 0)
	{
		cSymbol = '-';
		temp = 0 - temp;
	}

	m_strData.append(1, cSymbol);
	int iCount = 1;
	 
	while (temp)
	{
		m_strData.append(1, temp % 10 + '0');
		temp /= 10;
	}

	char *pLeft = (char*)(m_strData.c_str() + 1);
	char *pRight = (char*)(m_strData.c_str() + m_strData.size() - 1);
	while (pLeft < pRight)
	{
		char ctemp = *pLeft;
		*pLeft++ = *pRight;
		*pRight-- = ctemp;
	}

	 
}

bool BigData::IsINT64Owerflow()const
{
	std::string strTemp;
	if ('+' == m_strData[0])
	{
		strTemp = "+9223372036854775807";
	}
	else
	{
		strTemp = "-9223372036854775808";
	}

	if (m_strData.size() > strTemp.size())
	{
		return true;
	}
	else if (m_strData.size() == strTemp.size() && m_strData > strTemp)
	{
		return true;
	}

	return false;
}

std::ostream& operator<<(std::ostream& _cout, const BigData& bigData)
{
	if (!bigData.IsINT64Owerflow())  
	{
		_cout << bigData.m_llValue;
	}
	else
	{
		char* pData = (char*)bigData.m_strData.c_str();
		if (pData[0] == '+')
		{
			pData++;
		}
		_cout << pData;
	}
	return _cout;
}





