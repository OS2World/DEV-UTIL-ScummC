/* This file was generated, do not edit. */
static scc_param_help_t options_param_help[] = {
  {
    .name = "outbase",
    .arg = "base",
    .dfault = "frame",
    .desc = "Set the basename to use for the generated files."
  },{
    .name = "outfmt",
    .arg = "fmt",
    .dfault = "%s-%02d.bmp",
    .desc = "Set the format to use for the generated file names."
  },{
    .name = "dw",
    .arg = "width",
    .dfault = NULL,
    .desc = "Set the output frame width."
  },{
    .name = "dh",
    .arg = "height",
    .dfault = NULL,
    .desc = "Set the output frame height."
  },{}
};

static scc_param_help_t imgsplit_param_help[] = {
  {
    .name = "OPTIONS",
    .group = options_param_help
  },{}
};

static scc_help_t imgsplit_help = {
  .name = "imgsplit",
  .usage = "[OPTIONS] input.bmp ...",
  .param_help = imgsplit_param_help
};
