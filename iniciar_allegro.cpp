void iniciar_allegro(){
      allegro_init();
      install_keyboard();
      install_mouse();

      set_color_depth(32);
      set_gfx_mode(GFX_AUTODETECT_WINDOWED, 940, 600, 0, 0);

        if (install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, NULL) != 0)
            {   allegro_message("Error: inicializando !!!", allegro_error);
              //   return 1;
            }
        set_volume(80,80);
}
