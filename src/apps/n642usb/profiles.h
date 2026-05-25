// profiles.h - N642USB App Profiles
//
// Profile definitions for N64 to USB adapter (Xbox 360 Custom Layout)

#ifndef N642USB_PROFILES_H
#define N642USB_PROFILES_H

#include "core/services/profiles/profile.h"

// ============================================================================
// PROFILE: XBOX 360 CUSTOM MAPPING
// ============================================================================
// Mapeamento corrigido com nomenclatura interna do Joypad OS:
// N64 A (JP_BUTTON_B1) -> Xbox A (JP_BUTTON_B1)
// N64 B (JP_BUTTON_B3) -> Xbox X (JP_BUTTON_B3)
// N64 Z (JP_BUTTON_L2) -> Xbox R1 (JP_BUTTON_R1)
// Botões C             -> Desativados como botões digitais (atuam só no analógico)

static const button_map_entry_t n642usb_xbox_map[] = {
    // Botões Principais
    MAP_BUTTON(JP_BUTTON_B1, JP_BUTTON_B1),  // N64 A -> Xbox A
    MAP_BUTTON(JP_BUTTON_B3, JP_BUTTON_B3),  // N64 B -> Xbox X
    MAP_BUTTON(JP_BUTTON_L2, JP_BUTTON_R1),  // N64 Z (L2 interno) -> Xbox R1 (RB)

    // Desativa os botões C como botões digitais para evitar duplo comando
    MAP_BUTTON(JP_BUTTON_B2, 0),   // C-Down -> nada
    MAP_BUTTON(JP_BUTTON_B4, 0),   // C-Left -> nada
    MAP_BUTTON(JP_BUTTON_L3, 0),   // C-Up -> nada
    MAP_BUTTON(JP_BUTTON_R3, 0),   // C-Right -> nada
};

// ============================================================================
// PROFILE DEFINITIONS
// ============================================================================

static const profile_t n642usb_profiles[] = {
    // Perfil 0: Xbox 360 Customizado
    {
        .name = "xbox_layout",
        .description = "N64 para Xbox 360 (A=A, B=X, Z=R1, C=Analog)",
        .button_map = n642usb_xbox_map,
        .button_map_count = sizeof(n642usb_xbox_map) / sizeof(n642usb_xbox_map[0]),
        .combo_map = NULL,
        .combo_map_count = 0,
        PROFILE_TRIGGERS_DEFAULT, // Conversão de L/R para gatilhos analógicos
        PROFILE_ANALOG_DEFAULT,   // Mantém o analógico principal e o analógico C funcionando
        .adaptive_triggers = false,
    },
};

// ============================================================================
// PROFILE SET
// ============================================================================

static const profile_set_t n642usb_profile_set = {
    .profiles = n642usb_profiles,
    .profile_count = sizeof(n642usb_profiles) / sizeof(n642usb_profiles[0]),
    .default_index = 0, // Inicia direto no perfil Xbox
};

#endif // N642USB_PROFILES_H
