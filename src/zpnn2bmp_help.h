/* This file was generated, do not edit. */
static scc_param_help_t options_param_help[] = {
  {
    .name = "o",
    .arg = "file.bmp",
    .dfault = "zplane.bmp",
    .desc = "Set the output filename."
  },{
    .name = "w",
    .arg = "w",
    .dfault = NULL,
    .desc = "Set the zplane width."
  },{
    .name = "h",
    .arg = "h",
    .dfault = NULL,
    .desc = "Set the zplane height."
  },{}
};

static scc_param_help_t zpnn2bmp_param_help[] = {
  {
    .name = "OPTIONS",
    .group = options_param_help
  },{}
};

static scc_help_t zpnn2bmp_help = {
  .name = "zpnn2bmp",
  .usage = "[OPTIONS] file.zpnn",
  .param_help = zpnn2bmp_param_help
};
