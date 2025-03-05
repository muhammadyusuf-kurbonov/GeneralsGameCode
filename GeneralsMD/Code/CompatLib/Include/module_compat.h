#pragma once

class CComModule
{
  public:
    void Init(void*, HINSTANCE hInstance)
    {
      m_hInstance = hInstance;
    }
    void Term() {}

  private:
    HINSTANCE m_hInstance;
};

bool GetModuleFileName(HINSTANCE hInstance, char* buffer, int size);