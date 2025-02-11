/*
*********************************************************
*                Warning!!!!!!!                         *
*  This file must be saved with Windows 1252 Encoding   *
*********************************************************
*/

#if !defined (INCLUDED_DE_DE)
#define INCLUDED_DE_DE 1
#endif

#if INCLUDED_DE_DE == 1

//#include "rg_i18n_lang.h"
// Stand German

int de_de_fmt_Title_Date_Format(char *outstr, const char *datefmt, uint16_t day, uint16_t month, const char *weekday, uint16_t hour, uint16_t minutes, uint16_t seconds)
{
    return sprintf(outstr, datefmt, weekday, day, month, hour, minutes, seconds);
};

int de_de_fmt_Date(char *outstr, const char *datefmt, uint16_t day, uint16_t month, uint16_t year, const char *weekday)
{
    return sprintf(outstr, datefmt, weekday, day, month, year);
};

int de_de_fmt_Time(char *outstr, const char *timefmt, uint16_t hour, uint16_t minutes, uint16_t seconds)
{
    return sprintf(outstr, timefmt, hour, minutes, seconds);
};

const lang_t lang_de_de LANG_DATA = {
    .codepage = 1252,
    .extra_font = NULL,
    .s_LangUI = "UI Sprache",
    .s_LangTitle = "Titel Sprache",
    .s_LangName = "Deutsch",

    // Core\Src\porting\gb\main_gb.c =======================================
    .s_Palette = "Palette",
    //=====================================================================

    // Core\Src\porting\nes\main_nes.c =====================================
    //.s_Palette = "Palette" dul
    .s_Default = "Standard",
    //=====================================================================

    // Core\Src\porting\gw\main_gw.c =======================================
    .s_copy_RTC_to_GW_time = "RTC -> G&W Zeit",
    .s_copy_GW_time_to_RTC = "G&W Zeit -> RTC",
    .s_LCD_filter = "LCD filter",
    .s_Display_RAM = "Anzeigespeicher",
    .s_Press_ACL = "Dr�cke ACL oder Reset",
    .s_Press_TIME = "Dr�cke TIME [B+TIME]",
    .s_Press_ALARM = "Dr�cke ALARM [B+GAME]",
    .s_filter_0_none = "0-kein",
    .s_filter_1_medium = "1-mittel",
    .s_filter_2_high = "2-hoch",
    //=====================================================================

    // Core\Src\porting\odroid_overlay.c ===================================
    .s_Full = "\x7",
    .s_Fill = "\x8",

    .s_No_Cover = "kein Cover",

    .s_Yes = "Ja",
    .s_No = "Nein",
    .s_PlsChose = "Auswahl",
    .s_OK = "OK",
    .s_Confirm = "Best�tige",
    .s_Brightness = "Helligkeit",
    .s_Volume = "Lautst�rke",
    .s_OptionsTit = "Optionen",
    .s_FPS = "FPS",
    .s_BUSY = "ausgelastet",
    .s_Scaling = "Skalierung",
    .s_SCalingOff = "aus",
    .s_SCalingFit = "einpassen",
    .s_SCalingFull = "Vollbild",
    .s_SCalingCustom = "benutzerdef.",
    .s_Filtering = "Filterung",
    .s_FilteringNone = "keine",
    .s_FilteringOff = "aus",
    .s_FilteringSharp = "scharf",
    .s_FilteringSoft = "weich",
    .s_Speed = "Geschwindigkeit",
    .s_Speed_Unit = "x",
    .s_Save_Cont = "Speichern & fortsetzen",
    .s_Save_Quit = "Speichern & beenden",
    .s_Reload = "Neu laden",
    .s_Options = "Optionen",
    .s_Power_off = "Abschalten",
    .s_Quit_to_menu = "Verlassen (Hautptmen�)",
    .s_Retro_Go_options = "Retro-Go",

    .s_Font = "Schriftart",
    .s_Colors = "Farben",
    .s_Theme_Title = "UI Darstellung",
    .s_Theme_sList = "Einfache Liste",
    .s_Theme_CoverV = "Coverflow V",
    .s_Theme_CoverH = "Coverflow H",
    .s_Theme_CoverLightV = "CoverLight V",
    .s_Theme_CoverLightH = "CoverLight H",
    //=====================================================================

    // Core\Src\retro-go\rg_emulators.c ====================================
    .s_File = "Datei",
    .s_Type = "Typ",
    .s_Size = "Gr��e",
    .s_ImgSize = "Bildgr��e",
    .s_Close = "Schlie�en",
    .s_GameProp = "Eigenschaften",
    .s_Resume_game = "Spiel fortsetzen",
    .s_New_game = "Neues Spiel",
    .s_Del_favorite = "Favorit l�schen",
    .s_Add_favorite = "Favorit hinzuf�gen",
    .s_Delete_save = "Spielstand l�schen",
    .s_Confiem_del_save = "Spielstand wirklich l�schen?",
#if GAME_GENIE == 1
    .s_Game_Genie_Codes = "Game Genie Codes",
    .s_Game_Genie_Codes_Title = "GG Optionen",
    .s_Game_Genie_Codes_ON = "\x6",
    .s_Game_Genie_Codes_OFF = "\x5",
#endif
    //=====================================================================

    // Core\Src\retro-go\rg_main.c =========================================
    .s_Second_Unit = "s",
    .s_Version = "Ver.",
    .s_Author = "von",
    .s_Author_ = "\t\t+",
    .s_UI_Mod = "UI Mod",
    .s_Lang = "Deutsch",
    .s_LangAuthor = "LeZerb",
    .s_Debug_menu = "Debug Men�",
    .s_Reset_settings = "Einstellungen zur�cksetzen",
    //.s_Close                   = "Schlie�en",
    .s_Retro_Go = "�ber Retro-Go",
    .s_Confirm_Reset_settings = "Alle Einstellungen zur�cksetzen?",

    .s_Flash_JEDEC_ID = "Flash JEDEC ID",
    .s_Flash_Name = "Flash Name",
    .s_Flash_SR = "Flash SR",
    .s_Flash_CR = "Flash CR",
    .s_Smallest_erase = "Smallest erase",
    .s_DBGMCU_IDCODE = "DBGMCU IDCODE",
    .s_Enable_DBGMCU_CK = "DBGMCU CK aktivieren",
    .s_Disable_DBGMCU_CK = "DBGMCU CK deaktivieren",
    //.s_Close                   = "Schlie�en",
    .s_Debug_Title = "Debug",
    .s_Idle_power_off = "Abschalten bei Leerlauf",
    .s_Splash_Option = "Splash Animation",
    .s_Splash_On = "\x6",
    .s_Splash_Off = "\x5",

    .s_Time = "Zeit",
    .s_Date = "Datum",
    .s_Time_Title = "Zeit",
    .s_Hour = "Stunde",
    .s_Minute = "Minute",
    .s_Second = "Sekunde",
    .s_Time_setup = "Zeit setzen",

    .s_Day = "Tag",
    .s_Month = "Monat",
    .s_Year = "Jahr",
    .s_Weekday = "Wochentag",
    .s_Date_setup = "Datum setzen",

    .s_Weekday_Mon = "Mon",
    .s_Weekday_Tue = "Die",
    .s_Weekday_Wed = "Mit",
    .s_Weekday_Thu = "Don",
    .s_Weekday_Fri = "Fre",
    .s_Weekday_Sat = "Sam",
    .s_Weekday_Sun = "Son",

    .s_Title_Date_Format = "%s %02d.%02d. %02d:%02d:%02d",
    .s_Date_Format = "%s der %02d.%02d.20%02d",
    .s_Time_Format = "%02d:%02d:%02d",

    .fmt_Title_Date_Format = de_de_fmt_Title_Date_Format,
    .fmtDate = de_de_fmt_Date,
    .fmtTime = de_de_fmt_Time,

    //=====================================================================
    //           ------------ end ---------------
};

#endif
