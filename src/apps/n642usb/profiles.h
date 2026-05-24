// profiles.h - N642USB App Profiles
//
// Profile definitions for N64 to USB adapter (Xbox 360 Custom Layout)

#ifndef N642USB_PROFILES_H
#define N642USB_PROFILES_H

#include "core/services/profiles/profile.h"
#include "core/buttons.h" // Garante o acesso às definições corretas de botões do Joypad OS

// ============================================================================
// PROFILE: XBOX 360 CUSTOM MAPPING
// ============================================================================
// Mapeamento desejado:
// N64 A -> Xbox A (JOYPAD_BUTTON_A)
// N64 B -> Xbox X (JOYPAD_BUTTON_X)
// N64 Z -> Xbox R1/RB (JOYPAD_BUTTON_R1)
// N64 L/R -> Gatilhos L2/R2 (Tratados automaticamente no trigger_mode)
// Botões C -> Apenas Analógico Direito (Desativados como botões digitais)

static const button_map_entry_t n642usb_xbox_map[] = {
    // Botões Principais
    MAP_BUTTON(JOYPAD_BUTTON_A,  JOYPAD_BUTTON_A),  // N64 A -> Xbox A
    MAP_BUTTON(JOYPAD_BUTTON_B,  JOYPAD_BUTTON_X),  // N64 B -> Xbox X
    MAP_BUTTON(JOYPAD_BUTTON_Z,  JOYPAD_BUTTON_R1), // N64 Z -> Xbox R1 (RB)

    // Desativa os botões C como botões comuns de face para não darem duplo comando,
    // já que o sistema nativamente já os converte para o Analógico Direito.
    MAP_BUTTON(JOYPAD_BUTTON_C_DOWN,  0), 
    MAP_BUTTON(JOYPAD_BUTTON_C_LEFT,  0), 
    MAP_BUTTON(JOYPAD_BUTTON_C_UP,    0), 
    MAP_BUTTON(JOYPAD_BUTTON_C_RIGHT, 0), 
};

// ============================================================================
// PROFILE DEFINITIONS
// ============================================================================

static const profile_t n642usb_profiles[] = {
    // Perfil 0: customizado para o layout Xbox 360 que você pediu
    {
        .name = "xbox_layout",
        .description = "N64 para Xbox 360 customizado",
        .button_map = n642usb_xbox_map,
        .button_map_count = sizeof(n642usb_xbox_map) / sizeof(n642usb_xbox_map[0]),
        .combo_map = NULL,
        .combo_map_count = 0,
        // Faz com que os botões digitais L e R do N64 virem os gatilhos analógicos L2/R2 do Xbox
        .trigger_mode = PROFILE_TRIGGER_MODE_DIGITAL_TO_ANALOG, 
        PROFILE_ANALOG_DEFAULT,
        .adaptive_triggers = false,
    },
};

// ============================================================================
// PROFILE SET
// ============================================================================

static const profile_set_t n642usb_profile_set = {
    .profiles = n642usb_profiles,
    .profile_count = sizeof(n642usb_profiles) / sizeof(n642usb_profiles[0]),
    .default_index = 0, // Inicia direto nesse perfil modificado
};

#endif // N642USB_PROFILES_H
