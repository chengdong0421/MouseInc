HHOOK keyboard_hook;

//键盘钩子
LRESULT CALLBACK LowLevelKeyboardProc(int nCode, WPARAM wParam, LPARAM lParam)
{
    if ( nCode == HC_ACTION )
    {
        if (wParam == WM_KEYDOWN)
        {
            KBDLLHOOKSTRUCT *kb = (KBDLLHOOKSTRUCT*)lParam;
            switch(kb->vkCode)
            {
            case VK_VOLUME_DOWN:
            case VK_VOLUME_UP:
                //播放调节音效
                if(Config::GetInt(L"Other", L"VolumeSound", 1))
                {
                    ::PlaySound(L"SOUND", ::GetModuleHandle(NULL), SND_RESOURCE | SND_ASYNC | SND_NOSTOP | SND_NODEFAULT);
                }
                break;
            }
        }

    }
    return ::CallNextHookEx(keyboard_hook, nCode, wParam, lParam);
}