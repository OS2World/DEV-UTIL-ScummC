/* This file was generated, do not edit. */
static scc_param_help_t options_param_help[] = {
  {
    .name = "pals",
    .arg = "file.pals",
    .dfault = "default.pals",
    .desc = "Use the palette from a SCUMM PALS block."
  },{
    .name = "bmp",
    .arg = "file.bmp",
    .dfault = NULL,
    .desc = "Use the palette from a BMP image."
  },{}
};

static scc_param_help_t costview_param_help[] = {
  {
    .name = "OPTIONS",
    .group = options_param_help
  },{}
};

static scc_help_t costview_help = {
  .name = "costview",
  .usage = "[OPTIONS] file.cost",
  .param_help = costview_param_help
};
