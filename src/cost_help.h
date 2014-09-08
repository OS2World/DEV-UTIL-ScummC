/* This file was generated, do not edit. */
static scc_param_help_t options_param_help[] = {
  {
    .name = "o",
    .arg = "file.cost",
    .dfault = "output.cost",
    .desc = "Set the output file."
  },{
    .name = "I",
    .arg = "path",
    .dfault = ".",
    .desc = "Set the directory where the images are searched."
  },{
    .name = "akos",
    .arg = NULL,
    .dfault = NULL,
    .desc = "Output an AKOS (for v7) instead of a COST (for v6)."
  },{
    .name = "header",
    .arg = "file.h",
    .dfault = NULL,
    .desc = "Output a header file with defines for the animation names, etc."
  },{
    .name = "prefix",
    .arg = "p",
    .dfault = NULL,
    .desc = "Set a prefix on all the defines in the generated header."
  },{}
};

static scc_param_help_t cost_param_help[] = {
  {
    .name = "OPTIONS",
    .group = options_param_help
  },{}
};

static scc_help_t cost_help = {
  .name = "cost",
  .usage = "[OPTIONS] file.scost",
  .param_help = cost_param_help
};
