/* This file was generated, do not edit. */
static scc_param_help_t options_param_help[] = {
  {
    .name = "o",
    .arg = "output.bmp",
    .dfault = NULL,
    .desc = "Set the output file name."
  },{
    .name = "i",
    .arg = "input.bmp",
    .dfault = NULL,
    .desc = "Set the image to use for the picture."
  },{}
};

static scc_param_help_t palcat_param_help[] = {
  {
    .name = "OPTIONS",
    .group = options_param_help
  },{}
};

static scc_help_t palcat_help = {
  .name = "palcat",
  .usage = "[OPTIONS] input.bmp ...",
  .param_help = palcat_param_help
};
