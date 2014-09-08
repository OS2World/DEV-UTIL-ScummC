/* This file was generated, do not edit. */
static scc_param_help_t options_param_help[] = {
  {
    .name = "o",
    .arg = "output.voc",
    .dfault = "output.voc",
    .desc = "Set the output file name."
  },{
    .name = "r",
    .arg = "rate",
    .dfault = NULL,
    .desc = "Set the samplerate."
  },{}
};

static scc_param_help_t raw2voc_param_help[] = {
  {
    .name = "OPTIONS",
    .group = options_param_help
  },{}
};

static scc_help_t raw2voc_help = {
  .name = "raw2voc",
  .usage = "[OPTIONS] input.raw",
  .param_help = raw2voc_param_help
};
