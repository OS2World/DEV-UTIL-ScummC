/* This file was generated, do not edit. */
static scc_param_help_t input_param_help[] = {
  {
    .name = "font",
    .arg = "font.ttf",
    .dfault = NULL,
    .desc = "Use a font supported by Freetype (TTF, Type1, etc)."
  },{
    .name = "ibmp",
    .arg = "file.bmp",
    .dfault = NULL,
    .desc = "Use a BMP font."
  },{
    .name = "ichar",
    .arg = "file.char",
    .dfault = NULL,
    .desc = "Use a SCUMM charset."
  },{
    .name = "inut",
    .arg = "file.nut",
    .dfault = NULL,
    .desc = "Use a NUT charset."
  },{}
};

static scc_param_help_t output_param_help[] = {
  {
    .name = "ochar",
    .arg = "file.char",
    .dfault = NULL,
    .desc = "Create a SCUMM charset."
  },{
    .name = "obmp",
    .arg = "file.bmp",
    .dfault = NULL,
    .desc = "Create a BMP font."
  },{}
};

static scc_param_help_t BMP_input_param_help[] = {
  {
    .name = "ibmp-base",
    .arg = "b",
    .dfault = "0",
    .desc = "Set the index of the first character in the BMP font."
  },{}
};

static scc_param_help_t freetype_input_param_help[] = {
  {
    .name = "cw",
    .arg = "w",
    .dfault = "auto",
    .desc = "Set the character width in 1/64th of points."
  },{
    .name = "ch",
    .arg = "h",
    .dfault = "auto",
    .desc = "Set the character height in 1/64th of points."
  },{
    .name = "vdpi",
    .arg = "r",
    .dfault = "30",
    .desc = "Set the vertical resolution in dpi."
  },{
    .name = "hdpi",
    .arg = "r",
    .dfault = "30",
    .desc = "Set the horizontal resolution in dpi."
  },{
    .name = "vspace",
    .arg = "s",
    .dfault = "0",
    .desc = "Set the extra inter line space in pixel."
  },{}
};

static scc_param_help_t BMP_output_param_help[] = {
  {
    .name = "palsize",
    .arg = "s",
    .dfault = "auto",
    .desc = "Force the palette size (from 2 to 255)."
  },{
    .name = "bmp-width",
    .arg = "w",
    .dfault = "800",
    .desc = "Set the output image width."
  },{
    .name = "bmp-space",
    .arg = "s",
    .dfault = "8",
    .desc = "Set the character spacing."
  },{}
};

static scc_param_help_t options_param_help[] = {
  {
    .name = "BMP INPUT",
    .group = BMP_input_param_help
  },{
    .name = "FREETYPE INPUT",
    .group = freetype_input_param_help
  },{
    .name = "BMP OUTPUT",
    .group = BMP_output_param_help
  },{}
};

static scc_param_help_t char_param_help[] = {
  {
    .name = "INPUT",
    .group = input_param_help
  },{
    .name = "OUTPUT",
    .group = output_param_help
  },{
    .name = "OPTIONS",
    .group = options_param_help
  },{}
};

static scc_help_t char_help = {
  .name = "char",
  .usage = "INPUT OUTPUT [OPTIONS]",
  .param_help = char_param_help
};
