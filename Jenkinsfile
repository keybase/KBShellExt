 node ('windows-release'){
  stage 'Build'
  checkout scm
  bat 'msbuild KBShellExt.sln /p:Configuration=Release /p:Platform=x86 /t:Build'
 }