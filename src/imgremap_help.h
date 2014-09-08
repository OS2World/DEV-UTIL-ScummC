/* This file was generated, do not edit. */
static scc_param_help_t options_param_help[] = {
  {
    .name = "from",
    .arg = "c",
    .dfault = NULL,
    .desc = "Set the first color."
  },{
    .name = "to",
    .arg = "c",
    .dfault = NULL,
    .desc = "Set the second color."
  },{}
};

static scc_param_help_t imgremap_param_help[] = {
  {
    .name = "OPTIONS",
    .group = options_param_help
  },{}
};

static scc_help_t imgremap_help = {
  .name = "imgremap",
  .usage = "[OPTIONS] input.bmp ...",
  .param_help = imgremap_param_help
};
