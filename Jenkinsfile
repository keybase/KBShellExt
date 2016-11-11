 node ('windows-release'){
  stage 'Build'
  checkout scm
  bat '%ProgramFiles(x86)%\\Microsoft Visual Studio 14.0\\vc\\bin\\vcvars32.bat'
  bat 'MSBuild KBShellExt.sln /p:Configuration=Release /p:Platform=x86 /t:Build'
 }