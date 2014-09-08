/* This file was generated, do not edit. */
static scc_param_help_t options_param_help[] = {
  {
    .name = "dir",
    .arg = "path",
    .dfault = ".",
    .desc = "Directory where the datafiles are found."
  },{
    .name = "key",
    .arg = "k",
    .dfault = NULL,
    .desc = "Decryption key to use when reading the datafiles."
  },{
    .name = "dbg",
    .arg = NULL,
    .dfault = NULL,
    .desc = "Run in debugger mode."
  },{}
};

static scc_param_help_t scvm_param_help[] = {
  {
    .name = "OPTIONS",
    .group = options_param_help
  },{}
};

static scc_help_t scvm_help = {
  .name = "scvm",
  .usage = "[OPTIONS] basename",
  .param_help = scvm_param_help
};
